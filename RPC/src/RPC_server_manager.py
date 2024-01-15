import grpc
from concurrent import futures
import service_pb2
import service_pb2_grpc
import queue


class RPCServerManager(service_pb2_grpc.TemperatureServiceServicer):
    
    def __init__(self):
        self.data_queue = queue.Queue()
        
    def StreamTemperature(self,request,context):
        while True:
            try:
                temperature_data = self.temperature_data_queue.get()
                yield temperature_data
            except queue.Empty:
                continue
    
    def add_data(self,temperature,timestamp):
        temperature_data = service_pb2.TemperatureData(
            temperature = temperature,
            timestamp = timestamp
        )
        self.data_queue.put(temperature_data)
        
        
    
    def start_server(self):
        self.server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
        service_pb2_grpc.add_TemperatureServiceServicer_to_server(RPCServerManager(),self.server)
        self.server.add_insecure_port("[::]:50051")
        self.server.start()
        print("Server started on port 50051.")
        self.server.wait_for_termination()