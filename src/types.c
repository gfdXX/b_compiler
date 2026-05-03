#include "defs.h"
#include "data.h"
#include "decl.h"

// Return true if a type is an int type
// of any size, false otherwise
int inttype(int type)
{
    return ((type & 0xf) == 0);
}

// Return true if a type is of pointer type
int ptrtype(int type)
{
    return ((type & 0xf) != 0);
}

// Given a primitive type, return
// the type which is a pointer to it
int pointer_to(int type)
{
    if ((type & 0xf) == 0xf)
    {
        fatald("Unrecognised in pointer_to: type", type);
    }

    return (type + 1);
}

// Given a primitive pointer type, return
// the type which it points to
int value_at(int type)
{
    if ((type & 0xf) == 0x0)
    {
        fatald("Unrecognised in value_at: type", type);
    }
    
    return (type - 1);
}

// Given an AST tree and contextual type information, add only the
// widening/scaling nodes needed by this backend. B expressions are
// otherwise typeless machine words.
// If this will be part of a binary operation, the AST op is not zero.
struct ASTnode *modify_type(struct ASTnode *tree, int rtype, int op)
{
    int ltype;
    int lsize, rsize;

    ltype = tree->type;

    // B is typeless: every expression is a machine word. Keep only the
    // address scaling needed by this byte-addressed backend.
    // We can scale only on A_ADD or A_SUBTRACT operation
    if (op == A_ADD || op == A_SUBTRACT)
    {
        // Left is int type, right is pointer type and the size
        // of the original type is >1: scale the left
        if (inttype(ltype) && ptrtype(rtype)) {
            rsize = genprimsize(value_at(rtype));
            
            if (rsize > 1)
            {
                return (mkastunary(A_SCALE, rtype, tree, rsize));
            }
            else
            {
                return (tree);		// Size 1, no need to scale
            }
        }
    }

    if (op == 0 && inttype(ltype) && inttype(rtype) && ltype != rtype)
    {
        lsize = genprimsize(ltype);
        rsize = genprimsize(rtype);

        if (rsize > lsize)
        {
            return (mkastunary(A_WIDEN, rtype, tree, 0));
        }
    }

    return (tree);
}
