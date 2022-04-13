
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "PotatoInSpaceSystemComponent.h"

namespace PotatoInSpace
{
    void PotatoInSpaceSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PotatoInSpaceSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PotatoInSpaceSystemComponent>("PotatoInSpace", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PotatoInSpaceSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PotatoInSpaceService"));
    }

    void PotatoInSpaceSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PotatoInSpaceService"));
    }

    void PotatoInSpaceSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void PotatoInSpaceSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    PotatoInSpaceSystemComponent::PotatoInSpaceSystemComponent()
    {
        if (PotatoInSpaceInterface::Get() == nullptr)
        {
            PotatoInSpaceInterface::Register(this);
        }
    }

    PotatoInSpaceSystemComponent::~PotatoInSpaceSystemComponent()
    {
        if (PotatoInSpaceInterface::Get() == this)
        {
            PotatoInSpaceInterface::Unregister(this);
        }
    }

    void PotatoInSpaceSystemComponent::Init()
    {
    }

    void PotatoInSpaceSystemComponent::Activate()
    {
        PotatoInSpaceRequestBus::Handler::BusConnect();
    }

    void PotatoInSpaceSystemComponent::Deactivate()
    {
        PotatoInSpaceRequestBus::Handler::BusDisconnect();
    }
}
