# Generated by the gRPC Python protocol compiler plugin. DO NOT EDIT!
"""Client and server classes corresponding to protobuf-defined services."""
import grpc

import service_pb2 as service__pb2


class TemperatureServiceStub(object):
    """Missing associated documentation comment in .proto file."""

    def __init__(self, channel):
        """Constructor.

        Args:
            channel: A grpc.Channel.
        """
        self.StreamTemperature = channel.unary_stream(
                '/RPC.TemperatureService/StreamTemperature',
                request_serializer=service__pb2.StreamRequest.SerializeToString,
                response_deserializer=service__pb2.TemperatureData.FromString,
                )


class TemperatureServiceServicer(object):
    """Missing associated documentation comment in .proto file."""

    def StreamTemperature(self, request, context):
        """Missing associated documentation comment in .proto file."""
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')


def add_TemperatureServiceServicer_to_server(servicer, server):
    rpc_method_handlers = {
            'StreamTemperature': grpc.unary_stream_rpc_method_handler(
                    servicer.StreamTemperature,
                    request_deserializer=service__pb2.StreamRequest.FromString,
                    response_serializer=service__pb2.TemperatureData.SerializeToString,
            ),
    }
    generic_handler = grpc.method_handlers_generic_handler(
            'RPC.TemperatureService', rpc_method_handlers)
    server.add_generic_rpc_handlers((generic_handler,))


 # This class is part of an EXPERIMENTAL API.
class TemperatureService(object):
    """Missing associated documentation comment in .proto file."""

    @staticmethod
    def StreamTemperature(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            insecure=False,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_stream(request, target, '/RPC.TemperatureService/StreamTemperature',
            service__pb2.StreamRequest.SerializeToString,
            service__pb2.TemperatureData.FromString,
            options, channel_credentials,
            insecure, call_credentials, compression, wait_for_ready, timeout, metadata)
