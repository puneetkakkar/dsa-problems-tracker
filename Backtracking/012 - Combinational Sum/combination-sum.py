class Solution:
    def __init__(self):
        self.ans = []

    def findCombination(self, starting_index: int, target: int, ds: List, candidates: List):
        if starting_index == len(candidates):
            if target == 0:
                self.ans.append(ds.copy())
            return

        if candidates[starting_index] <= target:
            ds.append(candidates[starting_index])
            self.findCombination(starting_index, target -
                                 candidates[starting_index], ds, candidates)
            ds.pop()

        self.findCombination(starting_index + 1, target, ds, candidates)

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ds = []
        self.findCombination(0, target, ds, candidates)
        return self.ans
