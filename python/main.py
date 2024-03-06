from glob import glob
from utils import load_data, plot_trajectories

if __name__ == "__main__":
    plot_trajectories(load_data("../data/*"))
