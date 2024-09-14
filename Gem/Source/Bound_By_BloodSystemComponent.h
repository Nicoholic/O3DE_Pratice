
#pragma once

#include <AzCore/Component/Component.h>

#include <Bound_By_Blood/Bound_By_BloodBus.h>

namespace Bound_By_Blood
{
    class Bound_By_BloodSystemComponent
        : public AZ::Component
        , protected Bound_By_BloodRequestBus::Handler
    {
    public:
        AZ_COMPONENT_DECL(Bound_By_BloodSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        Bound_By_BloodSystemComponent();
        ~Bound_By_BloodSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // Bound_By_BloodRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
