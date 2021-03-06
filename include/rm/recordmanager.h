#ifndef RM_CORE_H
#define RM_CORE_H

#include "sqleast.h"
#include "pagefs/pagefs.h"

namespace sqleast {
    namespace rm {

        struct FileInfo {
            int recordSize;
            int slotPerPage;
            int slotBitmapSize;
            int firstEmptyPage;
            int totalPageNum;
        };

        struct PageHeader {
            int nextPage;
            int emptySlot;
            char *slotBitmap;

            PageHeader (int _nextPage, int _emptySlot, char *_slotBitmap):
                    nextPage(_nextPage), emptySlot(_emptySlot), slotBitmap(_slotBitmap) {}
        }; // should be created and released by core, cuz slotBitmap is variable-length

        class FileHandle;

        class RecordManager {

        public:
            static void createFile(char const *fileName, int dataSize, bool override = false);
            static FileHandle openFile(char const *fileName);
            static void destroyFile(char const *fileName);

        };
    }
}

#endif