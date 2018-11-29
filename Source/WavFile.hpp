#pragma once
#include <cstdint>
#include <fstream>

class WavFile
{
public:
    WavFile();
    ~WavFile();

    struct WavHeader
    {
        char chunkID[4];       // Should hold "RIFF"
        uint32_t fileLength;  // [File Size in bytes] - 8
        char format[4];         // Should hold "WAVE"
        char subchunk1ID[4];     // Should hold "fmt "
        uint32_t subchunk1Size;
        uint16_t formatTag;      // Should hold 1 to indicate PCM
        uint16_t numChannels;
        uint32_t sampleRate;
        uint32_t avgBytesPerSec;
        uint16_t blockAlign;
        uint16_t bitsPerSample;
        char subchunk2ID[4];    // Should hold "data"
        uint32_t subchuck2Size; // length of the array holding the audio
    } header;

    void load(const char* filename);
    void readHeader();
    void process();
    void save(const char* filename);
private:
    std::fstream fileStream;
};
