#include "WavFile.hpp"
#include <iostream>

WavFile::WavFile()
{

}

WavFile::~WavFile()
{
    if (fileStream.is_open())
        fileStream.close();
}

void WavFile::load(const char* file)
{
   fileStream.open(file, std::fstream::in | std::fstream::out | std::fstream::app);
}

void WavFile::process()
{
    // Do something to the WAV File
}

void WavFile::save(const char* file)
{
    std::fstream outFile;
    outFile.open(file, std::fstream::out);
    // Save the data to the outFile
    outFile.close();
}

void WavFile::readHeader()
{
    fileStream.read(reinterpret_cast<char*>(&header), sizeof(WavHeader));
    std::cout << "RIFF ID is "
        << header.chunkID[0]
        << header.chunkID[1]
        << header.chunkID[2]
        << header.chunkID[3]
        << std::endl;
    std::cout << "File length is "
        << header.fileLength
        << std::endl;
    std::cout << "Format ID is "
        << header.format[0]
        << header.format[1]
        << header.format[2]
        << header.format[3]
        << std::endl;
    std::cout << "Format subchunk ID is "
        << header.subchunk1ID[0]
        << header.subchunk1ID[1]
        << header.subchunk1ID[2]
        << header.subchunk1ID[3]
        << std::endl;
    std::cout << "Subchunk 1 Size is "
        << header.subchunk1Size
        << std::endl;
    std::cout << "Format Tag is "
        << header.formatTag
        << std::endl;
    std::cout << "Number of Channels is "
        << header.numChannels
        << std::endl;
    std::cout << "Sample rate is "
        << header.sampleRate
        << std::endl;
    std::cout << "Average bytes per second is "
        << header.avgBytesPerSec
        << std::endl;
    std::cout << "Block align is "
        << header.blockAlign
        << std::endl;
    std::cout << "Bits per sample is "
        << header.bitsPerSample
        << std::endl;
    std::cout << "Data subchunk ID is "
        << header.subchunk2ID[0]
        << header.subchunk2ID[1]
        << header.subchunk2ID[2]
        << header.subchunk2ID[3]
        << std::endl;
    std::cout << "Data subchunk size is "
        << header.subchuck2Size
        << std::endl;
}
