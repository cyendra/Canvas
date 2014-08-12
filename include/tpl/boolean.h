
#ifndef __TPL_BOOLEAN_H__
#define __TPL_BOOLEAN_H__

namespace tpl{
    namespace boolean{
        struct boolean{
        };
        namespace prim{
            struct $true:  boolean{};
            struct $false: boolean{};
        }
        using namespace prim;

        namespace logic{
            template<class Bool1,class Bool2>
            struct $and{
                using value = $false;
            };

            template<>
            struct $and<$true,$true>{
                using value = $true;
            };

            template<class Bool1, class Bool2>
            struct $or{
                using value = $true;
            };

            template<>
            struct $or<$false,$false>{
                using value = $false;
            };

            template<class Bool1>
            struct $not{
                using value = $false;
            };

            template<>
            struct $not<$false>{
                using value = $true;
            };
        }
        using namespace logic;
    }
}

#endif // __TPL_BOOLEAN_H__
