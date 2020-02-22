#ifndef GURUM_CONNECTION_WRAP_H
#define GURUM_CONNECTION_WRAP_H

#include <napi.h>

#include "simpledb/simpledb.h"
#include <atomic>

class Connection : public Napi::ObjectWrap<Connection> {
 public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  Connection(const Napi::CallbackInfo& info);

 private:
  static Napi::FunctionReference constructor;

  // Napi::Value dataSource(const Napi::CallbackInfo& info);
  // void SetDataSource(const Napi::CallbackInfo& info, const Napi::Value &value);
  
  // Napi::Value audioPid(const Napi::CallbackInfo& info);
  // Napi::Value hasAudio(const Napi::CallbackInfo& info);
  // Napi::Value videoPid(const Napi::CallbackInfo& info);
  // Napi::Value hasVideo(const Napi::CallbackInfo& info);
  

  // Napi::Value Prepare(const Napi::CallbackInfo& info);
  // void Start(const Napi::CallbackInfo& info);
  // void Stop(const Napi::CallbackInfo& info);
  // void Pause(const Napi::CallbackInfo& info);
  // void Seek(const Napi::CallbackInfo& info);

  // void EnableLog(const Napi::CallbackInfo& info, const Napi::Value &value);
  // Napi::Value log_enabled(const Napi::CallbackInfo& info);
  // Napi::Value duration(const Napi::CallbackInfo& info);

  // Napi::Value RequestPidChannel(const Napi::CallbackInfo& info);

  // Napi::Value FindStream(const Napi::CallbackInfo& info);

private:
  std::unique_ptr<util::db::Connection> connection_{};
  bool log_enabled_{false};
};

#endif // GURUM_CONNECTION_WRAP_H
