
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace PotatoInSpace
{
    class PotatoInSpaceRequests
    {
    public:
        AZ_RTTI(PotatoInSpaceRequests, "{43864615-4624-4fc2-918a-a1f191ede99b}");
        virtual ~PotatoInSpaceRequests() = default;
        // Put your public methods here
    };

    class PotatoInSpaceBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using PotatoInSpaceRequestBus = AZ::EBus<PotatoInSpaceRequests, PotatoInSpaceBusTraits>;
    using PotatoInSpaceInterface = AZ::Interface<PotatoInSpaceRequests>;

} // namespace PotatoInSpace
