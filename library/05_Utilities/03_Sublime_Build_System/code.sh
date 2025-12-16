{
    "shell_cmd": "g++ -std=c++17 \"${file}\" -o \"${file_path}/${file_base_name}\" && \"${file_path}/${file_base_name}\" < \"${file_path}/inputf.in\" > \"${file_path}/outputf.out\"",
    "working_dir": "${file_path}",
    "selector": "source.cpp"
}
