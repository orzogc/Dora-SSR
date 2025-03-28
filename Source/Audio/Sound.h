/* Copyright (c) 2016-2025 Li Jin <dragon-fly@qq.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#pragma once

#include "Basic/Object.h"

namespace SoLoud {
class Wav;
class WavStream;
class Soloud;
} // namespace SoLoud

NS_DORA_BEGIN

class SystemTimer;

class SoundFile : public Object {
public:
	virtual ~SoundFile();
	PROPERTY_READONLY_CALL(SoLoud::Wav*, Wav);
	virtual bool init() override;
	CREATE_FUNC_NULLABLE(SoundFile);

protected:
	SoundFile(OwnArray<uint8_t>&& data, size_t size);

private:
	OwnArray<uint8_t> _data;
	size_t _size;
	SoLoud::Wav* _wav;
	DORA_TYPE_OVERRIDE(SoundFile);
};

class SoundStream : public Object {
public:
	virtual ~SoundStream();
	PROPERTY_READONLY_CALL(SoLoud::WavStream*, Stream);
	virtual bool init() override;
	CREATE_FUNC_NULLABLE(SoundStream);

protected:
	SoundStream(OwnArray<uint8_t>&& data, size_t size);

private:
	size_t _size;
	OwnArray<uint8_t> _data;
	SoLoud::WavStream* _stream;
	DORA_TYPE_OVERRIDE(SoundStream);
};

class Audio : public NonCopyable {
public:
	PROPERTY_READONLY_CALL(SoLoud::Soloud*, SoLoud);
	virtual ~Audio();
	bool init();
	uint32_t play(String filename, bool loop = false);
	void stop(uint32_t handle);
	void playStream(String filename, bool loop = false, float crossFadeTime = 0.0f);
	void stopStream(float fadeTime = 0.0f);

protected:
	Audio();

private:
	uint32_t _currentVoice;
	Ref<SoundStream> _currentStream;
	SoLoud::Soloud* _soloud;
	SINGLETON_REF(Audio, Director);
};

#define SharedAudio \
	Dora::Singleton<Dora::Audio>::shared()

NS_DORA_END
