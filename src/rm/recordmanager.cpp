#include "rm/recordmanager.h"
#include "rm/filehandle.h"
#include "rm/exception.h"
#include "rm/bitmaputil.h"

namespace sqleast {
    namespace rm {

        using namespace pagefs;

        void RecordManager::createFile(char const *fileName, int recordSize, bool override) {
            PageFS &fs = PageFS::getInstance();
            fs.createFile(fileName, override);
            int fid = fs.openFile(fileName);
            rm::FileHandle handle(fid);

            FileInfo *infoPtr = (FileInfo*) fs.loadPage(fid, 0);
            infoPtr->firstEmptyPage = 0;
            infoPtr->recordSize = recordSize;
            // slot_n = 8 * (PAGE_SIZE - HEADER_SIZE) / (8 * rsize + 1)
            infoPtr->slotPerPage = ((PAGE_SIZE - (int)sizeof(PageHeader) + (int)sizeof(char *)) << 3) / ((recordSize << 3) + 1);
            infoPtr->slotBitmapSize = infoPtr->slotPerPage / 8 + (infoPtr->slotPerPage % 8 > 0);
            infoPtr->totalPageNum = 1;

            if (infoPtr->slotPerPage <= 0)
                throw RecordTooLargeException();

            fs.markDirty(fid, 0);
            fs.forcePage(fid, 0);
            fs.unpinPage(fid, 0);
        }

        FileHandle RecordManager::openFile(char const*fileName) {
            PageFS &fs = PageFS::getInstance();
            int fid = fs.openFile(fileName);
            return rm::FileHandle(fid);
        }

        void RecordManager::destroyFile(char const *fileName) {
            PageFS &fs = PageFS::getInstance();
            fs.destroyFile(fileName);
        }

    }
}