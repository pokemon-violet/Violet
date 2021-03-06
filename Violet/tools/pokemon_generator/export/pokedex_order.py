# Export pokemon order

def export_pokedex_order(stats, project, language='LANG_GER'):
    """ Creates a structure for pokedex order.
    
    Parameters:
    -----------
    stats : list
        A list of dicts representing the updated pokemon.
    project : pymap.project.Project
        The pymap project.
    language : str
        The language to export the structure in.
        
    Returns:
    --------
    pokedex_order : list
        The pokedex order.
    """
    return [stat.get('dex_number', 0) for stat in stats]