#pragma once
#include <memory>
#include "pimpl.h"

namespace SL {
	namespace Remote_Access_Library {
		namespace Utilities {
			struct Blk;
			struct BufferManagerImpl;
			class BufferManager {
				pimpl<BufferManagerImpl> _BufferManagerImpl;
			public:
				BufferManager(size_t max_buffersize = 1024 *1024 *64);//default 64MBs
				std::shared_ptr<Blk> AquireBuffer(size_t req_bytes);
				void ReleaseBuffer(std::shared_ptr<Blk>& buffer);
			};

			size_t getSize(const std::shared_ptr<Blk>& b);
			char * getData(const std::shared_ptr<Blk>& b);
		}
	}
}