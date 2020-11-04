class FatherClass:
    def __init__(self):
        super().__init__()
        self.name = 'FatherClass'
        self.type = 'Class'

    def hello(self, msg):
        print(self.name, msg)