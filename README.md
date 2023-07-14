# So_long

## <p align="center"> Project Overview 💡</p>
 The fifth project at 42 programming school.
 The so_long consists of a top-down game, which we code from scratch using the MiniLibx graphical library.
 It involves a series of validations from the map that is passed as argument, checks to prevent memoy leaks, the game engineering, managing windows, events, sprites and maps.


### How does it work?

- You'll be able to play once you install the [__MiniLibx__](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
 features or if you're using one of the machines at 42.

- To play, first compile the project with make :   _make_

- In case you wanna play the bonus version :  _make bonus_

- So, run :

         ./so_long

 followed by the map :

          /maps/map.ber

- For bonus :
  
         ./so_long_bonus

 followed bythe map :

           /maps/map.ber
           

# <p align="center"> Maps 🗺 </p>

- You can parse any kind of map, as long as it respects the below rules:
__The map must be a .ber file.__

And can only contain these characters:

|  CHAR  | OBJECT  |
| ------ | ------  |
|  1  |  Wall  |
|  C  |  Coin  |
|  E  |  Exit  |
|  P  |  Plyaer |
|  0  |  Floor  |

# <p align="center"> Controls 🎮	</p>

|  Key  | OBJECT  |
| ------ | ------  |
|W or ⬆️ |	Move up|
|A or ⬅️ | Move left|
|S or ⬇️ |	Move down|
|D or ➡️ |	Move right|
|Q or Esc |	Close the game|

Use WASD or arrow keys to move.

The map must be rectangular and surrounded by walls '1'.

The map must contain at least one exit, one collectible, and one starting position.

Check some examples in the folder /maps.

As in /maps/map.ber:


![163024984-1ff511c1-17d2-4eef-8d97-90cc8a884c73](https://github.com/B-azeddine/So_long/assets/74467756/c82064e1-7d58-40fc-9ecd-1e6fe56b6591)


# <p align="center"> We use techniques like ✍ : </p>

- Parsing and Validation
- Memory Management
- Game Loop
- Graphics Rendering
- Event Handling
- Collision Detection
- Map Rendering
- Game Logic and Rules
- Error Handling and Debugging
- Modular Design and Code Organization
  

# <p align="center"> Skills obtained 🏅 : </p>


 By successfully completing the so_long project, you'll acquire practical experience in:
 
 - graphical application development,
 - game engineering.
 - the utilization of the MiniLibx graphical library.
 - This project serves as a valuable opportunity to apply theoretical knowledge to real-world scenarios, and gain insights into the complexities of developing graphical games.
