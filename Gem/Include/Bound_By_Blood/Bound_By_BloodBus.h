
#pragma once

#include <Bound_By_Blood/Bound_By_BloodTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace Bound_By_Blood
{
    class Bound_By_BloodRequests
    {
    public:
        AZ_RTTI(Bound_By_BloodRequests, Bound_By_BloodRequestsTypeId);
        virtual ~Bound_By_BloodRequests() = default;
        // Put your public methods here
    };

    class Bound_By_BloodBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using Bound_By_BloodRequestBus = AZ::EBus<Bound_By_BloodRequests, Bound_By_BloodBusTraits>;
    using Bound_By_BloodInterface = AZ::Interface<Bound_By_BloodRequests>;

} // namespace Bound_By_Blood
