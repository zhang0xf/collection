import os

def generate_makefile(dir_path, binary_name):
    # 这里的 f"""...""" 是一个多行的格式化字符串，它会将 {binary_name} 替换为变量的值。
    content = f"""# Auto-generated Makefile for {binary_name}

BIN := {binary_name}

.PHONY: all clean

all: $(BIN)

$(BIN): main.go
\tgo build -o $(BIN) main.go

clean:
\trm -f $(BIN)
"""

    makefile_path = os.path.join(dir_path, 'Makefile')
    with open(makefile_path, 'w') as f:
        f.write(content)

    print(f"✅ Generated: {makefile_path}")

def main():
    root = os.getcwd()
    for chapter in sorted(os.listdir(root)):
        chapter_path = os.path.join(root, chapter)
        if not os.path.isdir(chapter_path):
            continue

        for example in sorted(os.listdir(chapter_path)):
            example_path = os.path.join(chapter_path, example)
            main_go = os.path.join(example_path, 'main.go')

            if os.path.isdir(example_path) and os.path.isfile(main_go):
                generate_makefile(example_path, example)

if __name__ == '__main__':
    main()
