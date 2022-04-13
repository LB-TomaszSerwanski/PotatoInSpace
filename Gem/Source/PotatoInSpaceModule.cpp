
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "PotatoInSpaceSystemComponent.h"

namespace PotatoInSpace
{
    class PotatoInSpaceModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(PotatoInSpaceModule, "{d3863298-0e8a-48f1-a661-b1bb57382d09}", AZ::Module);
        AZ_CLASS_ALLOCATOR(PotatoInSpaceModule, AZ::SystemAllocator, 0);

        PotatoInSpaceModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                PotatoInSpaceSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<PotatoInSpaceSystemComponent>(),
            };
        }
    };
}// namespace PotatoInSpace

AZ_DECLARE_MODULE_CLASS(Gem_PotatoInSpace, PotatoInSpace::PotatoInSpaceModule)
