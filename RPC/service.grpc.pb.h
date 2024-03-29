// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: service.proto
#ifndef GRPC_service_2eproto__INCLUDED
#define GRPC_service_2eproto__INCLUDED

#include "service.pb.h"

#include <functional>
#include <grpcpp/generic/async_generic_service.h>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/client_context.h>
#include <grpcpp/completion_queue.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/proto_utils.h>
#include <grpcpp/impl/rpc_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/status.h>
#include <grpcpp/support/stub_options.h>
#include <grpcpp/support/sync_stream.h>

namespace RPC {

class TemperatureService final {
 public:
  static constexpr char const* service_full_name() {
    return "RPC.TemperatureService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    std::unique_ptr< ::grpc::ClientReaderInterface< ::RPC::TemperatureData>> StreamTemperature(::grpc::ClientContext* context, const ::RPC::StreamRequest& request) {
      return std::unique_ptr< ::grpc::ClientReaderInterface< ::RPC::TemperatureData>>(StreamTemperatureRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::RPC::TemperatureData>> AsyncStreamTemperature(::grpc::ClientContext* context, const ::RPC::StreamRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::RPC::TemperatureData>>(AsyncStreamTemperatureRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::RPC::TemperatureData>> PrepareAsyncStreamTemperature(::grpc::ClientContext* context, const ::RPC::StreamRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::RPC::TemperatureData>>(PrepareAsyncStreamTemperatureRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void StreamTemperature(::grpc::ClientContext* context, const ::RPC::StreamRequest* request, ::grpc::ClientReadReactor< ::RPC::TemperatureData>* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientReaderInterface< ::RPC::TemperatureData>* StreamTemperatureRaw(::grpc::ClientContext* context, const ::RPC::StreamRequest& request) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::RPC::TemperatureData>* AsyncStreamTemperatureRaw(::grpc::ClientContext* context, const ::RPC::StreamRequest& request, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::RPC::TemperatureData>* PrepareAsyncStreamTemperatureRaw(::grpc::ClientContext* context, const ::RPC::StreamRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    std::unique_ptr< ::grpc::ClientReader< ::RPC::TemperatureData>> StreamTemperature(::grpc::ClientContext* context, const ::RPC::StreamRequest& request) {
      return std::unique_ptr< ::grpc::ClientReader< ::RPC::TemperatureData>>(StreamTemperatureRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::RPC::TemperatureData>> AsyncStreamTemperature(::grpc::ClientContext* context, const ::RPC::StreamRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::RPC::TemperatureData>>(AsyncStreamTemperatureRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::RPC::TemperatureData>> PrepareAsyncStreamTemperature(::grpc::ClientContext* context, const ::RPC::StreamRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::RPC::TemperatureData>>(PrepareAsyncStreamTemperatureRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void StreamTemperature(::grpc::ClientContext* context, const ::RPC::StreamRequest* request, ::grpc::ClientReadReactor< ::RPC::TemperatureData>* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientReader< ::RPC::TemperatureData>* StreamTemperatureRaw(::grpc::ClientContext* context, const ::RPC::StreamRequest& request) override;
    ::grpc::ClientAsyncReader< ::RPC::TemperatureData>* AsyncStreamTemperatureRaw(::grpc::ClientContext* context, const ::RPC::StreamRequest& request, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReader< ::RPC::TemperatureData>* PrepareAsyncStreamTemperatureRaw(::grpc::ClientContext* context, const ::RPC::StreamRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_StreamTemperature_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status StreamTemperature(::grpc::ServerContext* context, const ::RPC::StreamRequest* request, ::grpc::ServerWriter< ::RPC::TemperatureData>* writer);
  };
  template <class BaseClass>
  class WithAsyncMethod_StreamTemperature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_StreamTemperature() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_StreamTemperature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status StreamTemperature(::grpc::ServerContext* /*context*/, const ::RPC::StreamRequest* /*request*/, ::grpc::ServerWriter< ::RPC::TemperatureData>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestStreamTemperature(::grpc::ServerContext* context, ::RPC::StreamRequest* request, ::grpc::ServerAsyncWriter< ::RPC::TemperatureData>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(0, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_StreamTemperature<Service > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_StreamTemperature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_StreamTemperature() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackServerStreamingHandler< ::RPC::StreamRequest, ::RPC::TemperatureData>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::RPC::StreamRequest* request) { return this->StreamTemperature(context, request); }));
    }
    ~WithCallbackMethod_StreamTemperature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status StreamTemperature(::grpc::ServerContext* /*context*/, const ::RPC::StreamRequest* /*request*/, ::grpc::ServerWriter< ::RPC::TemperatureData>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerWriteReactor< ::RPC::TemperatureData>* StreamTemperature(
      ::grpc::CallbackServerContext* /*context*/, const ::RPC::StreamRequest* /*request*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_StreamTemperature<Service > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_StreamTemperature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_StreamTemperature() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_StreamTemperature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status StreamTemperature(::grpc::ServerContext* /*context*/, const ::RPC::StreamRequest* /*request*/, ::grpc::ServerWriter< ::RPC::TemperatureData>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_StreamTemperature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_StreamTemperature() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_StreamTemperature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status StreamTemperature(::grpc::ServerContext* /*context*/, const ::RPC::StreamRequest* /*request*/, ::grpc::ServerWriter< ::RPC::TemperatureData>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestStreamTemperature(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncWriter< ::grpc::ByteBuffer>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(0, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_StreamTemperature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_StreamTemperature() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackServerStreamingHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const::grpc::ByteBuffer* request) { return this->StreamTemperature(context, request); }));
    }
    ~WithRawCallbackMethod_StreamTemperature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status StreamTemperature(::grpc::ServerContext* /*context*/, const ::RPC::StreamRequest* /*request*/, ::grpc::ServerWriter< ::RPC::TemperatureData>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerWriteReactor< ::grpc::ByteBuffer>* StreamTemperature(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/)  { return nullptr; }
  };
  typedef Service StreamedUnaryService;
  template <class BaseClass>
  class WithSplitStreamingMethod_StreamTemperature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithSplitStreamingMethod_StreamTemperature() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::SplitServerStreamingHandler<
          ::RPC::StreamRequest, ::RPC::TemperatureData>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerSplitStreamer<
                     ::RPC::StreamRequest, ::RPC::TemperatureData>* streamer) {
                       return this->StreamedStreamTemperature(context,
                         streamer);
                  }));
    }
    ~WithSplitStreamingMethod_StreamTemperature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status StreamTemperature(::grpc::ServerContext* /*context*/, const ::RPC::StreamRequest* /*request*/, ::grpc::ServerWriter< ::RPC::TemperatureData>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with split streamed
    virtual ::grpc::Status StreamedStreamTemperature(::grpc::ServerContext* context, ::grpc::ServerSplitStreamer< ::RPC::StreamRequest,::RPC::TemperatureData>* server_split_streamer) = 0;
  };
  typedef WithSplitStreamingMethod_StreamTemperature<Service > SplitStreamedService;
  typedef WithSplitStreamingMethod_StreamTemperature<Service > StreamedService;
};

}  // namespace RPC


#endif  // GRPC_service_2eproto__INCLUDED
