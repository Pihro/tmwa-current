class XString(object):
    ''' print a XString
    '''
    __slots__ = ('_value')
    name = 'strings::XString'
    enabled = True

    def __init__(self, value):
        self._value = value

    def children(self):
        yield 'base', self._value['_base']

    def to_string(self):
        b = self._value['_b']['_ptr']
        e = self._value['_e']['_ptr']
        d = e - b
        return b.lazy_string(length=d)
