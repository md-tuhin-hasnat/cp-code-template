{
    "cmd": ["g++", "-std=c++17", "${file}",
            "-o", "${file_base_name}",
            "&&", "./${file_base_name}<inputf.in>outputf.out"],
    "shell": true,
    "working_dir": "$file_path",
    "selector": "source.cpp"
}
