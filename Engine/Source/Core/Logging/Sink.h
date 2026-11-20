#pragma once

#include "Log.h"
#include <cstdio>
#include <string>

namespace Hades
{
class ILogSink
{
public:
    virtual ~ILogSink() = default;
    virtual bool IsValid() const = 0;
    virtual void Log(const ELogLevel level, const char* message) = 0;
};

class CConsoleSink : public ILogSink
{
public:
    virtual bool IsValid() const override;
    virtual void Log(const ELogLevel level, const char* message) override;

private:
    std::string name;
};

class CFileSink : public ILogSink
{
public:
    CFileSink();
    virtual ~CFileSink();
    virtual bool IsValid() const override;
    virtual void Log(const ELogLevel level, const char* message) override;

private:
    FILE* file;
    std::string name;
};
}
