from abc import ABC, abstarctmethod

class Log(ABC):
    history = []
    
    def backup(self) -> None:
        ...
    
    def undo(self) -> None:
        if not len(self.history):
            return
        ...


class Object(ABC):
    @abstarctmethod
    def attach(self, observer: "Observer") -> None:
        ...
    
    @abstarctmethod
    def notify(self) -> None:
        pass

class Observer(ABC):
    @abstarctmethod
    def update(self, obj: Object):
        ...

class Player:
    ...

class PlayerObserver(Observer):
    state = False
    def update(self, obj: Object):
        if obj.hp == 0:
            self.state = True

class Game:
    ...


def main():
    ...

if __name__ == "__main__":
    main()
    