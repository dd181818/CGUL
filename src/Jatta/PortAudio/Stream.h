/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "StreamData.h"
#include "Device.h"
#include "StreamInfo.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace PortAudio
    {
        class Stream
        {
        private:
            Float32 volume;
        protected:
            _JATTA_PASTREAM stream;
            UInt32 sampleRate;
            UInt32 framesPerBuffer;
            UInt32 channelCount;
            StreamData data;
            _JATTA_EXPORT virtual SInt32 OpenStream(Device device);
        public:
            _JATTA_EXPORT Stream();
            _JATTA_EXPORT ~Stream();

            _JATTA_EXPORT virtual bool Update(StreamData* data) = 0;

            _JATTA_EXPORT SInt32 Start();
            _JATTA_EXPORT SInt32 Stop();
            _JATTA_EXPORT SInt32 Close();

            _JATTA_EXPORT void SetVolume(Float32 volume);
            _JATTA_EXPORT Float32 GetVolume();

            _JATTA_EXPORT bool IsStopped();
            _JATTA_EXPORT bool IsActive();
            _JATTA_EXPORT StreamInfo GetInfo();
            _JATTA_EXPORT double GetTime();
            _JATTA_EXPORT double GetCpuLoad();

            _JATTA_EXPORT StreamData* GetData();

            _JATTA_EXPORT SInt32 Read(void* buffer, UInt64 frames);
            _JATTA_EXPORT SInt32 Write(const void* buffer, UInt64 frames);
            _JATTA_EXPORT SInt64 ReadAvailable();
            _JATTA_EXPORT SInt64 WriteAvailable();
        };
    }
}
#include "../External/Undefines.h"