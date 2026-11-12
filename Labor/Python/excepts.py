
class DigitInName(Exception):
    def __init__(self, message: str):
        self.message = message
        super().__init__(self.message)
        
class PostcodeLengthError(Exception):
    def __init__(self, message: str):
        self.message = message
        super().__init__(self.message)
        