import numpy as np
import matplotlib.pyplot as plt
from glob import glob


def load_data(path: str = "../data/*") -> dict[str, np.ndarray]:
    files, data = glob(path), {}
    for file in files:
        name = file.split("_")[0].split("/")[-1]
        trajectories = []
        with open(file, 'r') as f:
            for line in f:
                str_arr = str(line)[1:-2:].split(", ")
                trajectories.append([float(str_arr[i]) for i in range(len(str_arr))])
        data[name] = np.concatenate(trajectories).reshape(-1, 3)
    return data


def plot_trajectories(data: dict[str, np.ndarray]) -> None:

    fig = plt.figure(figsize=(10, 10))
    ax = fig.add_subplot(111, projection='3d')

    # ax.plot(jupiter[:, 0], jupiter[:, 1], jupiter[:, 2], label='Jupiter')
    # ax.plot(sun[:, 0], sun[:, 1], sun[:, 2], label='Sun')

    for name, traj in data.items():
        if name.lower() == "sun":
            # plot sphere
            # Parameters for the sphere (Sun)
            radius = 25  # Adjust the radius as needed
            u, v = np.mgrid[0:2*np.pi:50j, 0:np.pi:50j]  # Spherical coordinate grids
            x = radius * np.sin(v) * np.cos(u)
            y = radius * np.sin(u) * np.sin(v)
            z = radius * np.cos(v)

            # Plotting the sphere
            ax.plot_surface(x, y, z, color='yellow', alpha=0.6)

        ax.plot(traj[:, 0], traj[:, 1], traj[:, 2], '.-', label=name)

    # Setting the axis limits
    ax.set_xlim([-150, 150])  # Set x-axis limits
    ax.set_ylim([-150, 150])  # Set y-axis limits
    ax.set_zlim([-150, 150])  # Set z-axis limits

    ax.set_xlabel('X Coordinate')
    ax.set_ylabel('Y Coordinate')
    ax.set_zlabel('Z Coordinate')
    ax.set_title('Trajectories of Celestial Bodies')
    ax.legend()
    plt.show()






