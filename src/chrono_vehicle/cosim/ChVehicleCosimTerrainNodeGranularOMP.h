// =============================================================================
// PROJECT CHRONO - http://projectchrono.org
//
// Copyright (c) 2020 projectchrono.org
// All right reserved.
//
// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file at the top level of the distribution and at
// http://projectchrono.org/license-chrono.txt.
//
// =============================================================================
// Authors: Radu Serban
// =============================================================================
//
// Definition of the OpenMP granular TERRAIN NODE (using Chrono::Parallel).
//
// The global reference frame has Z up, X towards the front of the vehicle, and
// Y pointing to the left.
//
// =============================================================================

#ifndef TESTRIG_TERRAINNODE_GRANULAR_OMP_H
#define TESTRIG_TERRAINNODE_GRANULAR_OMP_H

#include "chrono_parallel/physics/ChSystemParallel.h"

#include "chrono_vehicle/cosim/ChVehicleCosimTerrainNode.h"

namespace chrono {
namespace vehicle {

class CH_VEHICLE_API ChVehicleCosimTerrainNodeGranularOMP : public ChVehicleCosimTerrainNode {
  public:
    /// Create a Chrono::Parallel granular terrain subsystem.
    ChVehicleCosimTerrainNodeGranularOMP(ChContactMethod method,  ///< contact method (SMC or NSC)
                                         bool render,             ///< use OpenGL rendering
                                         int num_threads          ///< number of OpenMP threads
    );
    ~ChVehicleCosimTerrainNodeGranularOMP();

    virtual ChSystem* GetSystem() override { return m_system; }

    /// Set container wall thickness (default: 0.2)
    void SetWallThickness(double thickness);

    /// Set properties of granular material.
    void SetGranularMaterial(double radius,   ///< particle radius (default: 0.01)
                             double density,  ///< particle material density (default: 2000)
                             int num_layers   ///< number of generated particle layers (default: 5)
    );

    /// Set the material properties for terrain.
    /// The type of material must be consistent with the contact method (SMC or NSC)
    /// specified at construction. These parameters characterize the material for the container and
    /// (if applicable) the granular material.  Tire contact material is received from the rig node.
    void SetMaterialSurface(const std::shared_ptr<ChMaterialSurface>& mat);

    /// Specify whether contact coefficients are based on material properties (default: true).
    /// Note that this setting is only relevant when using the SMC method.
    void UseMaterialProperties(bool flag);

    /// Set the normal contact force model (default: Hertz)
    /// Note that this setting is only relevant when using the SMC method.
    void SetContactForceModel(ChSystemSMC::ContactForceModel model);
    
    /// Set the tangential contact displacement model (default: OneStep)
    /// Note that this setting is only relevant when using the SMC method.
    void SetTangentialDisplacementModel(ChSystemSMC::TangentialDisplacementModel model);

    /// Set sweeping sphere radius for proxy bodies (default 5e-3).
    /// This value is used as a "thickness" for collision meshes (a non-zero value can improve robustness of the
    /// collision detection algorithm).
    void SetProxyContactRadius(double radius) { m_radius_p = radius; }

    /// Initialize granular terrain from the specified checkpoint file (which must exist in the output directory).
    /// By default, particles are created uniformly distributed in the specified domain such that they are initially not
    /// in contact.
    void SetInputFromCheckpoint(const std::string& filename);

    /// Set simulation length for settling of granular material (default: 0.4).
    void SetSettlingTime(double time) { m_time_settling = time; }

    /// Enable/disable output during settling (default: false).
    /// If enabled, output files are generated with a frequency of 100 FPS.
    void EnableSettlingOutput(bool val) { m_settling_output = val; }

    /// Obtain settled terrain configuration.
    /// This is an optional operation that can be performed for granular terrain before initiating
    /// communictation with the rig node. For granular terrain, a settled configuration can
    /// be obtained either through simulation or by initializing particles from a previously
    /// generated checkpointing file.
    void Settle();

    /// Write checkpoint to the specified file (which will be created in the output directory).
    virtual void WriteCheckpoint(const std::string& filename) override;

  private:
    ChSystemParallel* m_system;  ///< containing system
    bool m_constructed;          ///< system construction completed?

    double m_hthick;  ///< container wall half-thickness

    double m_radius_p;  ///< radius for a proxy body

    bool m_use_checkpoint;              ///< initialize granular terrain from checkpoint file
    std::string m_checkpoint_filename;  ///< name of input checkpoint file

    int m_Id_g;                    ///< first identifier for granular material bodies
    int m_num_layers;              ///< number of generated particle layers
    unsigned int m_num_particles;  ///< number of granular material bodies
    double m_radius_g;             ///< radius of one particle of granular material
    double m_rho_g;                ///< particle material density

    double m_time_settling;  ///< simulation length for settling of granular material
    bool m_settling_output;  ///< output files during settling?

    virtual bool SupportsFlexibleTire() const override { return true; }

    virtual void Construct() override;

    /// Return current total number of contacts.
    int GetNumContacts() const { return m_system->GetNcontacts(); }

    virtual void CreateMeshProxies() override;
    virtual void UpdateMeshProxies() override;
    virtual void GetForcesMeshProxies() override;
    virtual void PrintMeshProxiesUpdateData() override;
    virtual void PrintMeshProxiesContactData() override;

    virtual void CreateWheelProxy() override;
    virtual void UpdateWheelProxy() override;
    virtual void GetForceWheelProxy() override;
    virtual void PrintWheelProxyUpdateData() override;
    virtual void PrintWheelProxyContactData() override;

    virtual void OnSynchronize(int step_number, double time) override;
    virtual void OnAdvance(double step_size) override;
    virtual void OnOutputData(int frame) override;

    /// Calculate current height of granular terrain. 
    double CalcCurrentHeight();

    void WriteParticleInformation(utils::CSV_writer& csv);

    static ChVector<> CalcBarycentricCoords(const ChVector<>& v1,
                                            const ChVector<>& v2,
                                            const ChVector<>& v3,
                                            const ChVector<>& vP);
};

}  // end namespace vehicle
}  // end namespace chrono

#endif
