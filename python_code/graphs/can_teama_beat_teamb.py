from collections import namedtuple, defaultdict

MatchResult = namedtuple('MatchResult', ('winning_team','losing_team'))

def can_team_a_beat_team_b(matches, team_a, team_b):
    def build_graph():
        graph = defaultdict(set)
        for match in matches:
            graph[match.winning_team].add(match.losing_team)
        return graph
    
    def is_reachable(graph, curr, dest, visited=set()):
        if curr == dest:
            return True
        elif curr in visited or curr not in graph:
            return False
        visited.add(curr)
        return any(is_reachable(graph, team, dest) for team in graph[curr])

    return is_reachable(build_graph(), team_a, team_b)


if __name__ == '__main__':
    matched = []
    matched.append(MatchResult('A','B'))
    matched.append(MatchResult('A','C'))
    matched.append(MatchResult('A','D'))
    matched.append(MatchResult('D','E'))
    matched.append(MatchResult('C','F'))
    matched.append(MatchResult('H','G'))
    if can_team_a_beat_team_b(matched, 'A', 'G'):
        print('POSSIBLE')
    else:
        print('NOT POSSIBLE')