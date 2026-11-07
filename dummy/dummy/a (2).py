from typing import Any, Callable
from dataclasses import dataclass

@dataclass
class Dummy:
    """Like Interaction"""
    id: int

class Command:
    """Command abstract"""
    def __init__(self):
        ...

    @classmethod
    def is_admin(cls, err: Callable[[Any, Any], Any]):
        """admin checker"""
        def decorator(func: Callable[[Any, Any], Any]):
            def wrapper(*args, **kwargs):
                """decorator pattern"""
                dummy, a = args[1], args[2]

                if dummy.id == 123:
                    return func(*args, **kwargs)
                
                return err(dummy, "your not admin")

            return wrapper
        
        return decorator
    
    @classmethod
    def error(cls, dummy: Dummy, message: str):
        print(f"message: {message}")


class A(Command):
    """init A"""
    def __init__(self):
        ...

    @Command.is_admin(Command.error)
    def command_a(self, dummy: Dummy, a: int):
        """command_a"""
        print(f"Hello, World! {a}")

if __name__ == "__main__":
    d = Dummy(id=123)
    A().command_a(d, 3)
