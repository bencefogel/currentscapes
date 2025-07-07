import os
import pickle

from tqdm import tqdm
from simulator.ModelSimulator import ModelSimulator

# simulation parameters
direction = 'IN'
simulated_dend = 108  # 20, 66, 86, 108, 117, 127

# generate simulation data
def run_simulation(direction, simulated_dend):
    simulator = ModelSimulator()
    model = simulator.build_model(dends=[simulated_dend])
    simulation_data_single, simulation_data_together = simulator.run_simulation(model, direction)

    with open(f'L:/simulation_data/gcar004/dendint_single_{direction}_{simulated_dend}.pkl', 'wb') as f:
        pickle.dump(simulation_data_single, f)

    with open(f'L:/simulation_data/gcar004/dendint_together_{direction}_{simulated_dend}.pkl', 'wb') as f:
        pickle.dump(simulation_data_together, f)

# dends = [20, 66, 86, 108, 117, 127]
dends = [86, 108, 117, 127]
for d in tqdm(dends):
    print(f"Running simulation for dendrite {d}")
    run_simulation('IN', d)
