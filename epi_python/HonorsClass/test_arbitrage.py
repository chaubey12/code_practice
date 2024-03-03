from typing import List
import math


def is_arbitrage_exist(graph: List[List[float]]) -> bool:
    def bellman_ford(graph, source):
        dis_to_source = ([float('inf')] * (source - 1) + [0] + [float('inf')]*(len(graph) - source))
        for _ in range(1, len(graph)):
            have_update = False
            for  i, row in enumerate(graph):
                for j, g in enumerate(row):
                    if(dis_to_source[i] != float('inf') and 
                       dis_to_source[j] > dis_to_source[i] + g):
                        have_update = True
                        dis_to_source[j] = dis_to_source[i]+ g
            
            if not have_update:
                return False
        
        return any(dis_to_source[i] != float('inf') and
                   dis_to_source[j] > dis_to_source[i] + g 
                   for i, row in enumerate(graph) for j, g in enumerate(row))
    return bellman_ford(
        [[-math.log10(edge) for edge in edge_list] for edge_list in graph], 0)

if __name__ == "__main__":
    exchange_rates = [
        [1, 0.8123, 0.6404, 78.125, 0.9784, 0.9924, 0.9465],
        [1,2275, 1, 0.7860, 96.55, 1.2010, 1.2182, 1.1616],
        [1.5617, 1.2724, 1, 122.83, 1.5280, 1.5498, 1.4778],
        [0.0128, 0.0104, 0.0081, 1, 1.2442, 0.0126, 0.0120],
        [1.0219, 0.8327, 0.6546, 80.39, 1, 1.0142, 0.9672],
        [1.0076, 0.8206, 0.6453, 79.26, 0.9859, 1, 0.9535],
        [1.0567, 0.8609, 0.6767, 83.12, 1.0339, 1.0487, 1]
    ]
    if is_arbitrage_exist(exchange_rates):
        print("Arbitrage Exists")
    else:
        print("No arbitrage exists")