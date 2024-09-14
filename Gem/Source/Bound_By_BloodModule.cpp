
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "Bound_By_BloodSystemComponent.h"

#include <Bound_By_Blood/Bound_By_BloodTypeIds.h>

namespace Bound_By_Blood
{
    class Bound_By_BloodModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(Bound_By_BloodModule, Bound_By_BloodModuleTypeId, AZ::Module);
        AZ_CLASS_ALLOCATOR(Bound_By_BloodModule, AZ::SystemAllocator);

        Bound_By_BloodModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                Bound_By_BloodSystemComponent::CreateDescriptor(),
            });
        }
        // hello hello
        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<Bound_By_BloodSystemComponent>(),
            };
        }
    };
}// namespace Bound_By_Blood

AZ_DECLARE_MODULE_CLASS(Gem_Bound_By_Blood, Bound_By_Blood::Bound_By_BloodModule)
