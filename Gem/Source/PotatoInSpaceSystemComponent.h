
#pragma once

#include <AzCore/Component/Component.h>

#include <PotatoInSpace/PotatoInSpaceBus.h>

namespace PotatoInSpace
{
    class PotatoInSpaceSystemComponent
        : public AZ::Component
        , protected PotatoInSpaceRequestBus::Handler
    {
    public:
        AZ_COMPONENT(PotatoInSpaceSystemComponent, "{3a8798c5-f649-4836-846b-e9472164b054}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        PotatoInSpaceSystemComponent();
        ~PotatoInSpaceSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // PotatoInSpaceRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
