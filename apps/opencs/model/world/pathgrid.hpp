#ifndef CSM_WOLRD_PATHGRID_H
#define CSM_WOLRD_PATHGRID_H

#include <string>
#include <vector>

#include <components/esm3/loadpgrd.hpp>

namespace CSMWorld
{
    struct Cell;
    template <typename T, typename AT>
    class IdCollection;

    template <typename ESXRecordT>
    struct IdAccessor;

    /// \brief Wrapper for Pathgrid record
    ///
    /// \attention The mData.mX and mData.mY fields of the ESM::Pathgrid struct are not used.
    /// Exterior cell coordinates are encoded in the pathgrid ID.
    struct Pathgrid : public ESM::Pathgrid
    {
        std::string mId;

        void load(ESM::ESMReader& esm, bool& isDeleted, const IdCollection<Cell, IdAccessor<Cell>>& cells);
        void load(ESM::ESMReader& esm, bool& isDeleted);
    };
}

#endif
