import pandas as pd

def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    col = ["student_id", "age"]
    result = pd.DataFrame(student_data, columns=col)
    return result
    