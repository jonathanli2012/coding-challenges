grid_0 = [
  [0,0,0,0,0,0,0,0],
  [0,0,0,0,0,0,0,0],
  [0,0,0,0,0,0,0,0],
  [0,0,0,0,0,0,0,0],
  [0,0,0,0,0,0,0,0],
  [0,0,0,0,0,0,0,0],
  [0,0,0,0,0,0,0,0]
]

grid_1 = [
  [0,0,1,0,0,0,0,0],
  [0,0,1,0,0,0,0,0],
  [0,0,0,0,0,1,0,0],
  [0,0,0,1,0,0,0,0],
  [0,1,0,0,0,1,0,0],
  [1,0,0,0,0,0,0,0],
  [0,0,0,0,0,0,0,1]
]
grid_2 = [
  [1,0,1,0,0,0,0,0],
  [1,0,1,0,0,0,0,0],
  [1,0,1,0,0,0,0,0],
  [1,0,1,0,0,0,0,0],
  [1,0,1,0,0,0,0,0],
  [1,0,1,0,0,0,0,0],
  [1,1,1,1,1,1,1,1]
]
grid_3 = [
  [1,0,1,0],
  [1,0,1,0],
  [1,0,1,0],
  [1,0,1,1]
]

def build_helper_grid(grid):
  x_len = len(grid[0])
  y_len = len(grid)
  
  grid_count = []
  count = 0

  for i in range(0,y_len):
    grid_count.append([])

    #we add an extra index so we can get
    #count including zeroth index of each line
    grid_count[i].append(count)

    for j in range(0,x_len):
      if(grid[i][j] == 1): count += 1
      grid_count[i].append(count)

  return grid_count

def main(grid, x1, y1, x2, y2):
  helper_grid = build_helper_grid(grid);
  
  count = 0
  y2 += 1
  x2 += 1

  for i in range(y1, y2):
    count += (helper_grid[i][x2] - helper_grid[i][x1])
  return count

print(main(grid_2,1,5,7,6))