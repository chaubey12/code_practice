import collections

MatchResult = collections.namedtuple('MatchResult', ('winning_team', 'losing_team'))

def can_tean_a_beat_team_b(matches, team_a, team_b):
    def build_graph(matches):
        graph = collections.defaultdict(set())
        for match in matches:
            graph[match.winning_team].add(match.losing_team)
        return graph
    def is_reachable_dfs(graph, curr, dest, visited=set()):
        if curr == dest:
            return True
        elif curr in visited or curr not in graph:
            return False
        visited.add(curr)
        return any(is_reachable_dfs(graph, team, dest) for team in graph[curr])
    return is_reachable_dfs(build_graph(matches), team_a, team_b)