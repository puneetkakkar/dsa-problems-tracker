from collections import defaultdict


class TrieNode:
    def __init__(self):
        self.child_node = defaultdict(TrieNode)
        self.is_word = False


class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        current = self.root

        for letter in word:
            index = ord(letter) - ord("a")
            current = current.child_node[index]
        current.is_word = True

    def search(self, word: str) -> bool:
        current = self.root

        for letter in word:
            index = ord(letter) - ord("a")
            current = current.child_node.get(index)
            if (current is None):
                return False

        return True if current.is_word == True else False

    def startsWith(self, prefix: str) -> bool:
        current = self.root

        for letter in prefix:
            index = ord(letter) - ord("a")
            current = current.child_node.get(index)
            if (current == None):
                return False

        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
