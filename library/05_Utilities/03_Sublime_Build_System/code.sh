{
    "shell_cmd": "g++ -std=c++17 -O2 -Wall -Wextra -DLOCAL \"${file}\" -o \"${file_path}/${file_base_name}\" && \"${file_path}/${file_base_name}\" < input.txt > output.txt",
    "file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
    "working_dir": "${file_path}",
    "selector": "source.c++",
    
    "variants":
    [
        {
            "name": "Run Only",
            "shell_cmd": "\"${file_path}/${file_base_name}\" < input.txt > output.txt"
        },
        {
            "name": "Compile Only",
            "shell_cmd": "g++ -std=c++17 -O2 -Wall -Wextra -DLOCAL \"${file}\" -o \"${file_path}/${file_base_name}\""
        },
        {
            "name": "Compile & Run (Console)",
            "shell_cmd": "g++ -std=c++17 -O2 -Wall -Wextra -DLOCAL \"${file}\" -o \"${file_path}/${file_base_name}\" && \"${file_path}/${file_base_name}\""
        },
        {
            "name": "Debug Build",
            "shell_cmd": "g++ -std=c++17 -g -Wall -Wextra -DLOCAL -fsanitize=address -fsanitize=undefined \"${file}\" -o \"${file_path}/${file_base_name}_debug\""
        }
    ],
    
    "windows": {
        "shell_cmd": "g++ -std=c++17 -O2 -Wall -Wextra -DLOCAL \"${file}\" -o \"${file_path}/${file_base_name}.exe\" && \"${file_path}/${file_base_name}.exe\" < input.txt > output.txt"
    },
    
    "linux": {
        "shell_cmd": "g++ -std=c++17 -O2 -Wall -Wextra -DLOCAL \"${file}\" -o \"${file_path}/${file_base_name}\" && \"${file_path}/${file_base_name}\" < input.txt > output.txt"
    },
    
    "osx": {
        "shell_cmd": "g++ -std=c++17 -O2 -Wall -Wextra -DLOCAL \"${file}\" -o \"${file_path}/${file_base_name}\" && \"${file_path}/${file_base_name}\" < input.txt > output.txt"
    }
}
