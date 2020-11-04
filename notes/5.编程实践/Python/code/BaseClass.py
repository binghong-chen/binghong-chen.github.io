class BaseClass:
    caseCount = 0
    def __init__(self):
        super().__init__()
        self.name = "BaseClass"
        self.type = "Class"
        self.model = 'BaseClass'
        BaseClass.caseCount += 1

    def hello(self, msg):
        print(self.name, msg)