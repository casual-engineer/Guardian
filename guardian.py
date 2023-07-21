import os

hosts_file_path = "C:\\Windows\\System32\\drivers\\etc\\hosts"
hosts_txt_path = "hosts.txt"

def read_hosts_file(filename):
    with open(filename, 'r') as file:
        return file.readlines()

def write_to_hosts_file(filename, lines):
    with open(filename, 'a') as file:
        for line in lines:
            file.write(line)
            print("Writing:", line.rstrip())

if __name__ == "__main__":
    # Read hosts.txt into a list
    try:
        with open(hosts_txt_path, 'r') as file:
            hosts_content = file.readlines()
    except FileNotFoundError:
        print(f"Error: Unable to open {hosts_txt_path}")
        exit(1)

    # Write contents of the list to the Windows hosts file
    try:
        write_to_hosts_file(hosts_file_path, hosts_content)
    except PermissionError:
        print(f"Error: Unable to open hosts file ({hosts_file_path})")
        exit(1)

    print("Contents written to hosts file successfully.")
