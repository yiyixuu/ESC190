# YVR ----- YYZ
#  |        /   |
#  |     /      |
#  |  /         |
# YUL ---- YOW
#   |
# YYC




from LL import LL

def make_graph():
    airports = {}

    yvr = LL()
    yvr.insert(0, "YYZ")
    yvr.insert(1, "YUL")

    yyz = LL()
    yyz.insert(0, "YVR")
    yyz.insert(1, "YUL")
    yyz.insert(2, "YOW")

    yul = LL()
    yul.insert(0, "YVR")
    yul.insert(1, "YYZ")
    yul.insert(2, "YOW")
    yul.insert(3, "YYC")

    yow = LL()
    yow.insert(0, "YYZ")
    yow.insert(1, "YUL")

    yyc = LL()
    yyc.insert(0, "YUL")

    for airport in ["YVR", "YYZ", "YUL", "YOW", "YYC"]:
        airports[airport] = eval(airport.lower())

    return airports


def are_linked(airports, a1, a2):
    cur = airports[a1].head
    while cur is not None:
        if cur.data == a2:
            return True
        cur = cur.next
    return False


if __name__ == "__main__":
    airports = make_graph()
    for airport in airports.keys():
        print(airport, end=": ")
        cur = airports[airport].head
        while cur is not None:
            print(cur.data, end=" ")
            cur = cur.next
        print()

    print(are_linked(airports, "YYC", "YYZ"))

