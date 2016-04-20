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
                type: 'datetime',
                dateTimeLabelFormats: {
                    day: '%e. %b',
                    month: '%b. \'%y',
                    year: '%Y'
                },
                title: {
                    text: 'Date'
                }
            },
            yAxis: {
                title: {
                    text: 'Price ([DEVIZA])'
                },
                min: 0
            },
            tooltip: {
                headerFormat: '<b>{series.name}</b><br>',
                pointFormat: '{point.x:%H:%M, %e. %b}: {point.y:.2f} [DEVIZA]'
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


