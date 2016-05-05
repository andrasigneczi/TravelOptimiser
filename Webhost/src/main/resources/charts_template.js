    $(function () {
        $('#[CONTAINER]').highcharts({
            chart: {
                type: 'line'
            },
            title: {
                text: '[TITLE]'
            },
            subtitle: {
                text: '[SUBTITLE]'
            },
            xAxis: {
               crosshair: {
                    width: 1,
                    color: 'blue',
                    snap: false,
                    zIndex: -1
                },
                type: 'datetime',
                dateTimeLabelFormats: {
                    day: '%e. %b',
                    month: '%b. \'%Y',
                    year: '%Y'
                },
                title: {
                    text: 'Date'
                }
            },
            yAxis: {
               crosshair: {
                    width: 1,
                    color: 'blue',
                    snap: false,
                    zIndex: -1
                },
                title: {
                        text: 'Price ([DEVIZA])'
                    },
                min: 0
            },
            tooltip: {
                headerFormat: '<b>{series.name}</b><br>',
                pointFormat: '{point.x:%e. %b, %H:%M}: {point.y:.2f} [DEVIZA]'
            },

            plotOptions: {
                line: {
                    marker: {
                        enabled: true
                    }
                }
            },

            series: [ [SERIES] ]
        });
    });


