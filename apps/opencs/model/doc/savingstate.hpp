#ifndef CSM_DOC_SAVINGSTATE_H
#define CSM_DOC_SAVINGSTATE_H

#include <deque>
#include <filesystem>
#include <fstream>
#include <map>

#include <components/esm3/esmwriter.hpp>

#include <components/to_utf8/to_utf8.hpp>

namespace CSMDoc
{
    class Operation;
    class Document;

    class SavingState
    {
        Operation& mOperation;
        std::filesystem::path mPath;
        std::filesystem::path mTmpPath;
        ToUTF8::Utf8Encoder mEncoder;
        std::ofstream mStream;
        ESM::ESMWriter mWriter;
        std::filesystem::path mProjectPath;
        bool mProjectFile;
        std::map<std::string, std::deque<int>> mSubRecords; // record ID, list of subrecords

    public:
        SavingState(Operation& operation, std::filesystem::path projectPath, ToUTF8::FromType encoding);

        bool hasError() const;

        void start(Document& document, bool project);
        ///< \param project Save project file instead of content file.

        const std::filesystem::path& getPath() const;

        const std::filesystem::path& getTmpPath() const;

        std::ofstream& getStream();

        ESM::ESMWriter& getWriter();

        bool isProjectFile() const;
        ///< Currently saving project file? (instead of content file)

        std::map<std::string, std::deque<int>>& getSubRecords();
    };

}

#endif
