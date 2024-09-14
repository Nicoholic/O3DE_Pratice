
#include <AzCore/Serialization/SerializeContext.h>

#include "Bound_By_BloodSystemComponent.h"

#include <Bound_By_Blood/Bound_By_BloodTypeIds.h>

namespace Bound_By_Blood
{
    AZ_COMPONENT_IMPL(Bound_By_BloodSystemComponent, "Bound_By_BloodSystemComponent",
        Bound_By_BloodSystemComponentTypeId);

    void Bound_By_BloodSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<Bound_By_BloodSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void Bound_By_BloodSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("Bound_By_BloodService"));
    }

    void Bound_By_BloodSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("Bound_By_BloodService"));
    }

    void Bound_By_BloodSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void Bound_By_BloodSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    Bound_By_BloodSystemComponent::Bound_By_BloodSystemComponent()
    {
        if (Bound_By_BloodInterface::Get() == nullptr)
        {
            Bound_By_BloodInterface::Register(this);
        }
    }

    Bound_By_BloodSystemComponent::~Bound_By_BloodSystemComponent()
    {
        if (Bound_By_BloodInterface::Get() == this)
        {
            Bound_By_BloodInterface::Unregister(this);
        }
    }

    void Bound_By_BloodSystemComponent::Init()
    {
        //test
    }

    void Bound_By_BloodSystemComponent::Activate()
    {
        Bound_By_BloodRequestBus::Handler::BusConnect();
    }

    void Bound_By_BloodSystemComponent::Deactivate()
    {
        Bound_By_BloodRequestBus::Handler::BusDisconnect();
    }
}
