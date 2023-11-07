/**init_builders(0);                     // Use seed 0 at the beginning of a game
init_tokens(0);                       // Same thing
current_player = get_random_player();
while nobody has won:
    if current_player.wishes_to_hire():
        available_cards = guild.get_available_builders()
        a_builder = current_player.select_affordable_builder()
        current_player.hire_builder(a_builder);
    else:
        available_tokens = marken.get_available_tokens()
        current_player.pick_tokens(available_tokens);
    current_player = next_player(current_player);*/