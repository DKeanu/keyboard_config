# keyboard_config
A repository for my keyboard configs.

# How to use
## Assumptions
- You have a custom keymap.c created already. Note that you need the .c version and not any other version (e.g .json).
- You have QMK CLI installed
- You have QMK Toolbox installed
- If on Windows then you must install QMK MSYS

## Compiling your custom keymap
- General keymap compiling code: `qmk compile -kb <path/to/keyboard/> -km <custom_keymap_name>`
- My current personal keymap compiling code: `qmk compile -kb keebio/iris/rev7 -km DKeanu_iris7`

## Flashing your keymap
If you are on Linux this proccess is very easy, you infact don't even need to compile first. The commands below will compile and flash in one go.
- General flashing command: `qmk flash -kb <my_keyboard> -km <my_keymap>`
- My current personal keymap flashing command: `qmk flash -kb keebio/iris/rev7 -km DKeanu_iris7`
- After executing this command put your keyboard into DFU Mode or as I call it flashing mode.

# Sources 
- [YouTube Video](https://www.youtube.com/watch?v=AA8fw2MbpYg) by [Josean Martinez](https://www.youtube.com/@joseanmartinez) that shows you how program your keyboard config with code rather than using the web based gui application [QMK Configurator](https://config.qmk.fm/). 
- QMK set up documentation can be found [here](https://docs.qmk.fm/newbs_getting_started).

