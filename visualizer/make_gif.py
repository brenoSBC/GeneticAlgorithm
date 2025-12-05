import imageio
import matplotlib.pyplot as plt
import numpy as np

def load_map(path="map.txt"):
    with open(path) as f:
        return [list(line.strip()) for line in f]

def load_moves(path="path.txt"):
    moves = []
    with open(path) as f:
        for line in f:
            dx, dy = map(int, line.split())
            moves.append((dx, dy))
    return moves

def generate_frames(map_grid, moves):
    frames = []
    H, W = len(map_grid), len(map_grid[0])

    x, y = 0, 0
    path = [(x, y)]

    for dx, dy in moves:
        new_x = x + dx
        new_y = y + dy

        if new_x < 0 or new_x >= H or new_y < 0 or new_y >= W:
            path.append((x, y))
        else:
            x, y = new_x, new_y
            path.append((x, y))

        fig, ax = plt.subplots()
  
        scale = 20
        dpi = fig.get_dpi()
        fig.set_size_inches((W * scale) / dpi, (H * scale) / dpi)

        plt.subplots_adjust(left=0, right=1, top=1, bottom=0)
        ax.set_position([0, 0, 1, 1])
        ax.axis("off")
        fig.patch.set_alpha(0)

        arr = np.zeros((H, W, 3), dtype=np.float32)

        for i in range(H):
            for j in range(W):
                if (i + j) % 2 == 0:
                    arr[i, j] = [0.12, 0.12, 0.12]
                else:
                    arr[i, j] = [0.08, 0.08, 0.08]

                if map_grid[i][j] == 'P':
                    arr[i, j] = [1.0, 0.4, 0.4]

        for px, py in path:
            if 0 <= px < H and 0 <= py < W:
                arr[px, py] = [0.0, 0.9, 0.95]

        ax.imshow(arr, interpolation="nearest")

        fig.canvas.draw()
        w, h = fig.canvas.get_width_height()
        image = np.frombuffer(fig.canvas.buffer_rgba(), dtype=np.uint8)
        image = image.reshape((h, w, 4))[:, :, :3]
        frames.append(image)

        plt.close(fig)

        if map_grid[x][y] == 'P':
            break

    return frames

def save_gif(frames, out="path.gif"):
    imageio.mimsave(out, frames, duration=0.20)
    print("GIF salvo como", out)

map_grid = load_map("map.txt")
moves = load_moves("path.txt")

frames = generate_frames(map_grid, moves)
save_gif(frames)
