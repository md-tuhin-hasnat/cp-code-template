"""
Team information collection and LaTeX generation.
"""

from pathlib import Path
import utils


def get_input_with_default(prompt, default):
    """
    Get user input with a default value.
    
    Args:
        prompt: Prompt message to display
        default: Default value if user presses Enter
        
    Returns:
        User input or default value
    """
    user_input = input(f"{prompt} [{default}]: ").strip()
    return user_input if user_input else default


def collect_team_info():
    """
    Collect team information from user with defaults.
    
    Returns:
        Dictionary with keys: 'title', 'team_name', 'members'
    """
    print("\n" + "="*60)
    print("Team Information Setup")
    print("="*60)
    print("Press Enter to use default values shown in brackets\n")
    
    # Collect team information
    title = get_input_with_default("Contest Title", "ICPC 2025 Code Template")
    team_name = get_input_with_default("Team Name", "Team Awesome")
    
    # Get number of members
    num_members_str = get_input_with_default("Number of team members", "3")
    try:
        num_members = int(num_members_str)
    except ValueError:
        print(f"Invalid number, using default: 3")
        num_members = 3
    
    # Collect member names
    default_members = ["Alice Johnson", "Bob Smith", "Charlie Davis"]
    members = []
    print(f"\nEnter names for {num_members} team members:")
    for i in range(num_members):
        default_name = default_members[i] if i < len(default_members) else f"Member {i+1}"
        member_name = get_input_with_default(f"  Member {i+1}", default_name)
        members.append(member_name)
    
    print("\n" + "="*60)
    print("Team Information Summary:")
    print("="*60)
    print(f"Title: {title}")
    print(f"Team Name: {team_name}")
    print(f"Members ({num_members}):")
    for i, member in enumerate(members, 1):
        print(f"  {i}. {member}")
    print("="*60 + "\n")
    
    return {
        'title': title,
        'team_name': team_name,
        'members': members
    }


def generate_team_info_tex(team_info, output_path):
    """
    Generate team_info.tex file with team metadata.
    
    Args:
        team_info: Dictionary with team information
        output_path: Path where team_info.tex should be written
    """
    with output_path.open('w', encoding='utf-8') as f:
        f.write('% Auto-generated team information - DO NOT EDIT MANUALLY\n\n')
        
        # Define LaTeX commands for team info (with escaping)
        escaped_title = utils.escape_latex(team_info["title"])
        escaped_team_name = utils.escape_latex(team_info["team_name"])
        
        f.write(f'\\newcommand{{\\contesttitle}}{{{escaped_title}}}\n')
        f.write(f'\\newcommand{{\\teamname}}{{{escaped_team_name}}}\n')
        
        # Write member list
        f.write('\\newcommand{\\teammembers}{\n')
        for i, member in enumerate(team_info['members'], 1):
            escaped_member = utils.escape_latex(member)
            f.write(f'  {i}. {escaped_member}\\\\\n')
        f.write('}\n')
