# Snake Game Design

## Game Initialization

1. Create grid
2. Select cell to make the snake
3. Create array of empty cells
4. Select random cell to place apple
5. Initialize move direction
6. Start movement

## Event Loop

1. Move snake head in current direction and make the rest of the snake follow
   - snake represented as a list of cells that it currently takes up
2. If the snake moves over an apple, append to tail of snake without moving the head of the snake for one loop
3. If the snake hits the edge of the screen, GAME OVER
4. If there is no more room for the snake to move, WIN
5. Move snake in direction of arrow key unless the arrow key is opposite of the current direction. In that case, do nothing

## Choosing a random cell to place the apple

1. Keep array of empty cells that gets updated when snake moves
2. Randomly select cell from array to place apple
3. Swap cell with the last cell in the array and remove the selected cell from the array
